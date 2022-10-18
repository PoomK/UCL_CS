#Breaking Ceasar's Cipher

def break_cipher(text):

    #Create variables for texts
    cipherText = text
    plainText = ""

    #Shift arrays according to position change
    alphaArray = ["A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z"]
    shiftedArray = ["A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z"]

    for i in range(0,12):
        shiftedArray.append(shiftedArray.pop(0))
        i += 1

    #Create list for cipherText and plainText
    cipherList = list(cipherText)
    plainList = []

    #Change characters of each position of cipherList
    for i in range(0,len(cipherList)):
        print(str(cipherList[i]))
        letterPos = int(alphaArray.index(str(cipherList[i])))+1
        plainList.append(str(shiftedArray[letterPos]))

    plainText = ''.join(plainList)

    print("Decrypted text:", plainText)

break_cipher("URYYB")