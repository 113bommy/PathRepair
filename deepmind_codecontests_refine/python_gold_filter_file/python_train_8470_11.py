y=int(input())
for i in range(y+1,9013):
    if(len(set(str(i)))==4):
        print(i)
        break