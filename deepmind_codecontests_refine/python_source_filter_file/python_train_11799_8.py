import math
import copy
def main():
       #from the begining we know that er have 2 possibilities
       #the most left house and the most right house
       possibilities = 2
       #get input
       numberOfHouses, size = map(int,input().split())
       #we will store not centers coordinates, but left coordinate
       LeftHouseCoordinate = []
       #and the size of each house in village
       HousesSizes = []
       #for this we have to read the input lune by line, each input coresponds to one house
       for _ in range(numberOfHouses):
              #we have house center coordinate and house length(houses are squares)
              center, HouseSize = map(int,input().split())
              #we want the left coordinate so we substract from center 1/2 of house size
              LeftHouseCoordinate.append(center - HouseSize/2)
              HousesSizes.append(HouseSize)
       #we want to sort the LeftHouseCoordinate in increasing order
       LeftCoordinateCopy = copy.deepcopy(LeftHouseCoordinate)
       LeftHouseCoordinate.sort()
       ordonateHousesSizes = [0]*numberOfHouses
       for index in range(numberOfHouses):
              for copyCoordinateIndex in range(numberOfHouses):
                     if LeftCoordinateCopy[copyCoordinateIndex] == LeftHouseCoordinate[index]:
                            ordonateHousesSizes[index] = HousesSizes[copyCoordinateIndex]
       #we want to find how many houses can fit in the distance between 2 houses
       for i in range(numberOfHouses - 1):
              #if between houses there is space for at least one house of size = size
              if LeftHouseCoordinate[i+1]-LeftHouseCoordinate[i] - ordonateHousesSizes[i] >= size + 1:
                     #then there can fit 2 houses because our house has to touch one neighbor house
                     possibilities += 2
              elif LeftHouseCoordinate[i+1]-LeftHouseCoordinate[i] - ordonateHousesSizes[i] == size:
                     possibilities += 1
       print(possibilities)

main()