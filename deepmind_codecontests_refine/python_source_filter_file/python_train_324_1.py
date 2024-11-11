n=int(input())
a=list(map(int,input().split()))

codd=0;ceven=0;odd=[];even=[]
for i in a:
     if i%2==0:
          ceven+=1
          even.append(i)
     else:
          codd+=1
          odd.append(i)
even.sort(reverse=True)
odd.sort(reverse=True)

if abs(codd-ceven)<=1:
     print(0)
else:
     if ceven>codd:
          temp=ceven-codd-1
          print(sum(even[n-temp:]))
     else:
          temp=codd-ceven-1
          print(sum(odd[n-temp:]))
