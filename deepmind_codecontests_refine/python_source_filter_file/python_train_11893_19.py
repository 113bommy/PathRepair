from sys import stdin,stdout                           #
import math                                            #
import heapq                                           #
                                                       #
t = 1                                                  #
def aint():                                            #
	return int(input().strip())                        #
def lint():                                            #
	return list(map(int,input().split()))              #
def fint():                                            #
	return list(map(int,stdin.readline().split()))     #
                                                       #	
########################################################

def main():
	#solve
	k=aint()
	print("3 3")
	print(pow(2,18)-1,pow(2,17),pow(2,17))
	print(pow(2,17),pow(2,17)-1,pow(2,17))
	print(pow(2,17),pow(2,17),k)

#t=int(input())

########################################################
for i in range(t):                                     #
	main()                                             #