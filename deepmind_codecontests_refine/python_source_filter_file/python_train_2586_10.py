n=int(input())
a=[input() for i in range(n)]
bu=0
end=-1
for i in range(n):
   if bu==1:
    end=i-1
    break
  bu=a[bu]-1
print(end)