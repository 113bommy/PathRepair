n, k = (int(i) for i in input().split())
j = 0
ratings = [[pos, rat, 1, 1] for pos, rat in enumerate([int(i) for i in input().split()])] #[position, rating, left_jump, right_jump]
sorted_by_rating = sorted(ratings, key = lambda r: r[1], reverse = True)
final = [0 for i in range(n)]
t = 0
for i in range(n):
    index = sorted_by_rating[i][0] 
    if final[index] == 0:       
        t = 1 + t % 2    
        final[index] = t
        left_x = 0
        right_x = 0
        
        num = k
        x = index - 1        
        while x >= 0 and num != 0:
            if final[x] == 0:
                final[x] = t
                left_x = x
                x -= ratings[x][2]                
                num -= 1
            else:
                x -= ratings[x][2]
                
        num = k
        x = index + 1
        while x < n and num != 0:
            if final[x] == 0:
                final[x] = t
                right_x = x
                x += ratings[x][3]                  
                num -= 1
            else:
                x += ratings[x][3]
                
        ratings[left_x][3] = right_x - left_x
        ratings[right_x][2] = right_x - left_x
        
        
for i in final:
    print(i, end = '')