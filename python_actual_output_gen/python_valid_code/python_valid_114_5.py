s=input()
w=int(input())
for i in range(len(s)//w):
    print(s[i*w],end='')