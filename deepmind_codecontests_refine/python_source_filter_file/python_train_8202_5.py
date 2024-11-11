n = int(input())
i=1
a=[]
while i*i<n:
    if n%i ==0 and not i==n//i:
        a.append(n//i)
    i+=1
print(sum(a)-len(a))