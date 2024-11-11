#!/usr/bin/env python
def budgetedMove(budget,cost,number):
    if budget ==0 or budget < cost or number == 0:
        return (budget,0)
    if number > 0 :
        ns= list(range(number))
        ns.reverse()
        for n in ns:
            if budget > n*cost:
                return (budget-n*cost, n)


def main():
   testcases = int(input())
   for t in range(testcases):
       i_s= input()
       n_piles,days= [int(i) for i in i_s.split(" ")]
       piles = [int(i) for i in input().split(" ")]
       n_total=piles[0]
       for i in range(len(piles)):
           if i==0:
               continue
           [days,inc]=budgetedMove(days,i,piles[i])
           n_total+=inc
       print(n_total)








if __name__ == '__main__':
    main()
