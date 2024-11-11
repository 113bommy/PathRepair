a,b=input().split()
count=0
for i in range(int(a),int(b)+1):
    if str(i)==str(i)[::-1]:
        count+=1
print(count)