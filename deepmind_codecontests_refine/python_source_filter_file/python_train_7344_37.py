
def main():
     juice = list(map(int, input().split(' ')))
     liters = list(map(int,input().split(' ')))
     cup = 0
     count = 0
     for i in range(len(liters)):
          if liters[i] <= juice[1]:
               cup += liters[i]
          if cup > juice[2]:
               count+=1
               cup-=0
     print(count)

if __name__ == '__main__':
    main()
