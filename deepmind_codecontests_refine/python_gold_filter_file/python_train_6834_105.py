k=int(input())
a=''
if k>36:
    print(-1)
    quit()
if k%2==0:
    a=a + '8'*(k//2)
else:
    a=a + '8'*(k//2) + "6"
print(int(a))
