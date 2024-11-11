def chickens (total) :
        if total%3== 0  or total%7 == 0 :
                return "YES"
        else :
                if total%3 == 1 and total//2 >= 2 :
                        return "YES"
                elif total%3 == 2 and total//2 >= 4 :
                        return "YES"
        return "NO"


test = int(input())
for x in range(test) :
        print (chickens(int(input())))
                        
