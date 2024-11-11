n=int(input())
s=input()
ind=0
for i in range(n-1):
    if s[i]>s[i+1]:
        ind=i
        break

s=s[:ind]+s[ind+1:]
print(s)
    
