def ans(S1,S2,S3,S4,w,h):
    return(max(max(max(S1)-min(S1),max(S2)-min(S2))*h,max(max(S3)-min(S3),max(S4)-min(S4))))
for _ in range(int(input())):
    a,b = map(int,input().split(" "))
    S1 = list(map(int,input().split(" ")))[1::]
    S2 = list(map(int,input().split(" ")))[1::]
    S3 = list(map(int,input().split(" ")))[1::]
    S4 = list(map(int,input().split(" ")))[1::]
    print(ans(S1,S2,S3,S4,a,b))