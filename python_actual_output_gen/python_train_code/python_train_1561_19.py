str1=str(input())

vowel="AEIOUaeiou"

str2=""
str3=str1.lower()

for i in str3:
    if i not in vowel:
        str2+="." + i



print(str2)
        
        
    
