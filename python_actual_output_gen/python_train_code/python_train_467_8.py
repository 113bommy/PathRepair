ans_list = ('1/6', '1/3', '1/2', '4/6', '5/6', '1/1')
 
x,y = map(int, input().split())
 
z = 6 - max(x,y)
 
print(ans_list[z])