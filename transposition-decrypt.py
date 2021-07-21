import math,pyperclip

def main():
    myMessage = 'Cenoonommstmme oo snnio. s s c'
    myKey = 8
    plainText = decryptMessage(myKey,myMessage)
    print(plainText+'|')
    pyperclip.copy(plainText)

def decryptMessage(key,message):
    numOfColumns = math.ceil(len(message)/key)
    numOfRows = key
    numOfShadedboxes = (numOfColumns*numOfRows)-len(message)
    plainText = ['']*numOfColumns
    col =0
    row = 0
    for symbol in message:
        plainText[col]+=symbol
        col += 1
        if(col == numOfColumns)or(col==numOfColumns-1 and row>=numOfRows-numOfShadedboxes):
            col = 0
            row = 1
        return ''.join(plainText)

if __name__ == '__main__':
    main()
