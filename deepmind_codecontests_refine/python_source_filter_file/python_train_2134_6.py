ab = list(map(int,input().split()))
ab1 = list(map(int,input().split()))
ab2 = list(map(int,input().split()))
if ((ab1[0] + ab2[0] <= ab[0] and max(ab1[1],ab2[0]) <= ab[1]) or
   (ab1[0] + ab2[1] <= ab[0] and max(ab1[1],ab2[0]) <= ab[1]) or
   (ab1[1] + ab2[0] <= ab[0] and max(ab1[0],ab2[1]) <= ab[1]) or
   (ab1[1] + ab2[1] <= ab[0] and max(ab1[0],ab2[0]) <= ab[1]) or
   (ab1[0] + ab2[0] <= ab[1] and max(ab1[1],ab2[0]) <= ab[0]) or
   (ab1[0] + ab2[1] <= ab[1] and max(ab1[1],ab2[0]) <= ab[0]) or
   (ab1[1] + ab2[0] <= ab[1] and max(ab1[0],ab2[1]) <= ab[0]) or
   (ab1[1] + ab2[1] <= ab[1] and max(ab1[0],ab2[0]) <= ab[0]) ):
           print("YES")
else:
           print("NO")
