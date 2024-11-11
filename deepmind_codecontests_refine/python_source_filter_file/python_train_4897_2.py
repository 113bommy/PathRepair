n = int(input())
for i in range(1,n+1):
    if i % 3 == 0 or str(i).find("3"):
        print(" " + str(i),end = "")
print()
