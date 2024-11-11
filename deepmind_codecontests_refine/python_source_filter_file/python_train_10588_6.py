x1,y1,x2,y2,x3,y3,x4,y4=map(int,input().split())
second=[[x1,y1],[x2,y2],[x3,y3],[x4,y4]]
x1,y1,x2,y2,x3,y3,x4,y4=map(int,input().split())
first=[[x1,y1],[x2,y2],[x3,y3],[x4,y4]]
first.sort()
second.sort()
if(second[0][0]>first[3][0]):
    print("NO")
elif(second[3][0]<first[0][0]):
    print("NO")
elif(second[1][1]<first[1][1]):
    print("NO")
elif(second[2][1]>first[2][1]):
    print("NO")
elif(first[0][0]+first[0][1]-first[3][0]-first[3][1]>=0 and second[0][0]+second[0][1]-first[3][0]-first[3][1]<0):
    print("NO")
elif(first[0][0]+first[0][1]-first[3][0]-first[3][1]<0 and second[0][0]+second[0][1]-first[3][0]-first[3][1]>=0):
    print("NO")    
elif(first[3][0]+first[3][1]-first[0][0]-first[0][1]>=0 and second[3][0]+second[3][1]-first[0][0]-first[0][1]<0):
    print("NO")
elif(first[3][0]+first[3][1]-first[0][0]-first[0][1]<0 and second[3][0]+second[3][1]-first[0][0]-first[0][1]>=0):
    print("NO")        
elif(first[0][0]-first[0][1]-first[3][0]+first[3][1]>=0 and second[1][0]-second[1][1]-first[3][0]+first[3][1]<0):
    print("NO")
elif(first[0][0]-first[0][1]-first[3][0]+first[3][1]<0 and second[1][0]-second[1][1]-first[3][0]+first[3][1]>=0):
    print("NO") 
elif(first[3][0]-first[3][1]-first[0][0]+first[0][1]>=0 and second[2][0]-second[2][1]-first[0][0]+first[0][1]<0):
    print("NO")
elif(first[3][0]-first[3][1]-first[0][0]+first[0][1]<0 and second[2][0]-second[2][1]-first[0][0]+first[0][1]>=0):
    print("NO")          
else:
    print("YES")