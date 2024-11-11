def main():
       rowsNr, colsNr, presidentColor = input().split()
       desks = []
       #get the input with all information about desks position and color
       for _ in range(int(rowsNr)):
              desks.append(input())
       #define the list of neighbors which we want to check
       neighbors = [[1,0],[0,-1],[-1,0],[0,1]]
       #define the set deputies, because there can be 2 desks with the same color and we don't want to count it twice
       deputies = set()
       #iterate over each desk
       for row in range(int(rowsNr)):
              for col in range(int(colsNr)):
                     #if we found president desk
                     if desks[row][col] == presidentColor:
                            #then we have to look for all neighbors if they exist and put them in the set
                            for neighbor in neighbors:
                                   if row + neighbor[0] < int(rowsNr) and col + neighbor[1] < int(colsNr) and row + neighbor[0] > 0 and col + neighbor[1] > 0:
                                          #if it is not an empty desk or president desk
                                          if desks[row + neighbor[0]][col + neighbor[1]] != '.' and desks[row + neighbor[0]][col + neighbor[1]] != presidentColor:
                                                 deputies.add(desks[row + neighbor[0]][col + neighbor[1]])
              
       print(len(deputies))


main()