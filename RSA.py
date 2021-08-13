# Implementation of RSA Algorithm

import random


def crypt(number):
    if(prime(number)):
        return number-1
    else:
        return False


def prime(n):  # check if the number is prime
    if (n <= 1):
        return False
    if (n <= 3):
        return True
    if (n % 2 == 0 or n % 3 == 0):
        return False
    i = 5
    while(i * i <= n):
        if (n % i == 0 or n % (i+2) == 0):
            return False
        i += 6
    return True


def generate_E(num):
    def mdc(n1, n2):
        rest = 1
        while(n2 != 0):
            rest = n1 % n2
            n1 = n2
            n2 = rest
        return n1

    while True:
        e = random.randrange(2, num)
        if(mdc(num, e) == 1):
            return e


def generate_prime():  # generate the prime number - p e q
    while True:  # 2**2048 is the RSA standart keys
        # define the range of the prime Num to be assumed
        x = random.randrange(1, 100)
        if(prime(x) == True):
            return x


def mod(a, b):  # mod function
    if(a < b):
        return a
    else:
        c = a % b
        return c


def cipher(words, e, n):  # get the words and compute the cipher
    tam = len(words)
    i = 0
    list = []
    while(i < tam):
        letter = words[i]
        k = ord(letter)
        k = k**e
        d = mod(k, n)
        list.append(d)
        i += 1
    return list


def read(x, n, d):
    list = []
    i = 0
    size = len(x)
    while i < size:
        result = x[i]**d
        text = mod(result, n)
        k = chr(text)
        list.append(k)
        i += 1
    return list

# A function to Calculate the Rrivate Key


def calculate_private_key(toti, e):
    d = 0
    while(mod(d*e, toti) != 1):
        d += 1
    return d


# MAIN
if __name__ == '__main__':
    text = input("Insert message: ")
    p = generate_prime()  # generates random P
    q = generate_prime()  # generates random Q
    n = p*q  # compute N
    y = crypt(p)
    x = crypt(q)
    crypt_de_N = x*y
    e = generate_E(crypt_de_N)  # generate E
    public_key = (n, e)

    print('Your public key:', public_key)
    text_cipher = cipher(text, e, n)
    print('Your encrypted message:', text_cipher)
    d = calculate_private_key(crypt_de_N, e)
    print('Your private key is:', d)
    original_text = read(text_cipher, n, d)
    print('your original message:', original_text)
