myStr=input().lower()
vowels=['a','i','o','u','e']
newStr=''.join(['.'+l for l in myStr if l not in vowels]);
print(newStr)
