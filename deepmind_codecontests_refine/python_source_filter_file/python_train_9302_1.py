
n,d,l = map(int,input().split())

max_sum = l*((n+1)//2)
min_sum = (n+1)//2

s = d+((n)//2)
v = d+l*((n)//2)
if s>max_sum or v<min_sum:
    print(-1)
else:
    i=0
    j = 0
    even = [1]*((n)//2)
    ho = len(even)
    odd = [1]*((n+1)//2)
    yo = len(odd)
    # print(max_sum,min_sum)
    while sum(even)+d<=min_sum :
      if i == ho:
          i = 0

      even[i]+=1
      if sum(even)+d>=max_sum:
          even[i]-=1
          break
      i+=1
    s = sum(even)+d
    # print(even,s)
    while sum(odd)!=s:
        if j == yo:
            j = 0

        odd[j]+=1
        j+=1




    o = 0
    e = 0
    for i in range(n):
       if i%2!=0:
           print(even[e],end = ' ')
           e+=1
       else:
           print(odd[o],end = ' ')
           o+=1

