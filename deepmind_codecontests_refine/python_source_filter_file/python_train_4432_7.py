def main():
    seat = input()
    n = int(seat[:-1])
    s = seat[-1]
    time = "0fedabc".index( s )
    time += 14 * ( ( n - 1 ) // 4 )
    if n & 1 == 0:
        time += 7
    print( time )
if __name__ == "__main__":
    main()
