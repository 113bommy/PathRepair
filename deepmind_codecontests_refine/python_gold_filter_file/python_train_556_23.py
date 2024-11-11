def check_magic (tiles) :
    if (tiles[0][0] + tiles[0][1] + tiles [0][2]) == (tiles[1][0] + tiles[1][1] + tiles [1][2])\
       == (tiles[2][0] + tiles[2][1] + tiles [2][2]) == (tiles[0][0] + tiles[1][0] + tiles [2][0])\
       == (tiles[0][1] + tiles[1][1] + tiles [2][1]) == (tiles[0][2] + tiles[1][2] + tiles [2][2])\
       == (tiles[0][0] + tiles[1][1] + tiles [2][2]) == (tiles[0][2] + tiles[1][1] + tiles [2][0]) :
        return 0


def magic_square (tiles) :
    sum_levels = []
    for x in tiles :
        sum_levels.append(sum(x))

    biggest = max(sum_levels)
    for x in range(100001) :
        tiles [0][0] = biggest - sum_levels[0] + x
        tiles [1][1] = biggest - sum_levels[1] + x
        tiles [2][2] = biggest - sum_levels[2] + x

        if check_magic (tiles) == 0 :
            break
        
    
   

    return tiles






tiles = []

for x in range(3) :
    tiles.append(list(map(int,input().split())))

tiles = magic_square(tiles)

for x in tiles :
    for y in x :
        print (y,end=" ")
    print ("\n",end="")
    
    
        
            
