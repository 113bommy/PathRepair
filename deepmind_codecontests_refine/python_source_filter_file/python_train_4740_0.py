n=int(input())
array=[str(t).zfill(4) for t in range(10000) if len(set(str(t).zfill(4)))==4]
print (array)
for _ in range(n):
    a,b,c=input().split()
    b=int(b)
    c=int(c)
    # for u in array:
        # print (u, set(u).intersection(set(a)))
    array=[u for u in array if len(set(u).intersection(set(a)))==b+c and sum(u[i]==a[i] for i in range(4))==b]
    # print (array)
if len(array)>1:print("Need more data")
elif len(array)==1:print(array[0])
else:print("Incorrect data")
