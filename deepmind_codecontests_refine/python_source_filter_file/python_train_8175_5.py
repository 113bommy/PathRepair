#!/usr/bin/python3

def main():
	s = input()
	spal = True
	#print( spal )
	ss = ""
	for i , c in enumerate( s[::-1] ):
		if c in "WTUIOAHXVMwuioxvm" :
			ss += c
		elif c in "qdbp":
			ss += "qdbp"[ 3 - "qdbp".index( c ) ]
		else:
			spal = False
			#print( "hey hey hey" , c )
			break

	if s != ss:
		spal = False

	print( "TAK" if spal else "NIE" )

if __name__ == '__main__':
	main()