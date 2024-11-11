h,w=map(int,input().split())
p=[["."]*(w+2)]+[["."]+list(map(str,input()))+["."]for i in range(w)]+[["."]*(w+2)]
print(["No","Yes"][int(all([any([p[i+x[0]][I+x[1]]=="#"for x in [[0,1],[0,-1],[1,0],[-1,0]]])for I in range(1,w+1)for i in range(1,h+1)if p[i][I]=="#"]))])