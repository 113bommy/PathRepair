arr=input()
countex=0
countin=0
for i in range(0,len(arr),5):
    if(arr[i:i+5]=="heavy"):
        countin+=1
    if(arr[i:i+5]=="metal"):
        countex+=countin
print(countex)