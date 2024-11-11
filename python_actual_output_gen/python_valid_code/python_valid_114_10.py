s=input()
w=int(input())
a=''
for i in range(0,len(s)//w):
    a+=s[w*i]
print(a)