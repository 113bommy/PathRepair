students=list(map(int,input().split(" ")))
participated=list(map(int,input().split(" ")))
participated.sort()
count=0
for i in participated:
    if(i<(5-students[1])):
        count+=1
    else:
        break
print(count//3)
