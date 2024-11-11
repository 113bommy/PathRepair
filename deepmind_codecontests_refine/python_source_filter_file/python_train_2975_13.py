liste=[[] for i in range(3)]
for i in range(3):
    liste[i]=[int(element) for element in input().split(' ')]

res=[]
#parallele au segment [b,c]
new_point_x=liste[0][0]+(liste[2][0]-liste[1][0])
new_point_y=liste[0][1]+(liste[2][1]-liste[1][1])
res.append(str(new_point_x)+' '+str(new_point_y))

#parallele au segment [a,b]
new_point_x=liste[2][0]-(liste[0][0]-liste[1][0])
new_point_y=liste[2][1]-(liste[0][1]-liste[1][1])
res.append(str(new_point_x)+' '+str(new_point_y))

#parallele au segment [a,c]
new_point_x=liste[1][0]-(liste[2][0]-liste[0][0])
new_point_y=liste[1][1]-(liste[2][1]-liste[0][1])
res.append(str(new_point_x)+' '+str(new_point_y))

print( ('\n').join(res))