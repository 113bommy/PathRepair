x=input()

word=input()

key1="qwertyuiop"
key2="asdfghjkl;"
key3="zxcvbnm,./"

if x=="S":
    for i in range(len(word)):
        if word[i] in key1:
            for j in range(len(key1)):
                if word[i]==key1[j]:
                    print(key1[j+1],end="")
        if word[i] in key2:
            for j in range(len(key2)):
                if word[i]==key2[j]:
                    print(key2[j+1],end="")
        if word[i] in key3:
            for j in range(len(key3)):
                if word[i]==key3[j]:
                    print(key3[j+1],end="")
if x=="R":
    for i in range(len(word)):
        if word[i] in key1:
            for j in range(len(key1)):
                if word[i]==key1[j]:
                    print(key1[j-1],end="")
        if word[i] in key2:
            for j in range(len(key2)):
                if word[i]==key2[j]:
                    print(key2[j-1],end="")
        if word[i] in key3:
            for j in range(len(key3)):
                if word[i]==key3[j]:
                    print(key3[j-1],end="")
                    
    

    