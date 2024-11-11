num=int(input())
a=[]
even=[]
odd=[]
a=input().split()
for i in range(num):
    if int(a[i])%2==0:
        even.append(i)
    else:
        odd.append(i)
if len(odd)>len(even):
    for i in even:
        print(i)
else:
    for i in odd:
        print(i)
        