stri = input()
prev = -1
maxi = -999999
vowel = "AEIOU"
i = 0
for i,j in enumerate(stri):
    if vowel.find(j)!=-1:
        maxi = max(i-prev,maxi)
        prev = i

maxi = max(i-prev+1,maxi)
print(maxi)
