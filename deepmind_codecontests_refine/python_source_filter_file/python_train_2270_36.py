k = int(input().split()[1])
s = input()
print(s[0:k]+s[k:k+1].lower()+s[k+1:len(s)+1])