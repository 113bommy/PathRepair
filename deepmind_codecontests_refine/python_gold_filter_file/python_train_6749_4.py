n=int(input())

ll = sorted([list(map(int, input().split())) for _ in range(n)], key=lambda x: -x[1])

mm=sorted([list(map(int,input().split())) for _ in range(n)])
count_num=0
for i,j in mm:
  for k,h in ll:
    if k<=i and h<=j:
      count_num+=1
      ll.remove([k,h])
      break
print(count_num)
