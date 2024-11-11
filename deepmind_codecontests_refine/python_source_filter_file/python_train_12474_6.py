s=input()
w=int(input())
for i in range(len(s)//w+1):
    print(s[i*w],end='')