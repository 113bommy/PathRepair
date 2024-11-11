try :
    import sys
    x, k = map(int, input().split(" "))
    lengthList = []
    lengthList = [int(p) for p in input().split(" ") for _ in range(0, x)]
    val = []
    val = [n for n in lengthList if (float(k/n)).is_integer() == True]
    y = max(val)
    print(int(k/y))
except OSError as err:
    print("OS error: {0}".format(err))
except ValueError as ex:
    print("Could not convert data to an integer.")
    print("value error: {0}".format(ex))
except:
    print("Unexpected error:", sys.exc_info()[0])
    #raise