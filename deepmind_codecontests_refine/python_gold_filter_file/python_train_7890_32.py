input()
B = input()
k = int(input())
for v in B:
    print(v if B[k-1] == v else "*",end="")
