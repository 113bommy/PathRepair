import sys

a=[str(input()) for x in range(8)]
for x in a:
    if x=="WBWBWBWB" :
        continue
    elif x=="BWBWBWBW":
        continue
    else:
        print(x,"NO")
        sys.exit()
print("YES")