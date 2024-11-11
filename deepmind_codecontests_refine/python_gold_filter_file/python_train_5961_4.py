import sys

def draw_square(center):
    (x,y) = center
    coords = [(x+1,y),(x+2,y),(x,y+1),(x+2,y+1),(x,y+2),(x+1,y+2),(x+2,y+2)]
    for (x_,y_) in coords:
        print(x_,y_)
    return (x+2,y+2)

def solve():
    gray_cells = int(input())
    print(8 + 7 * gray_cells)
    print(0,0)
    center = draw_square((0,0))
    for _ in range(gray_cells):
        center = draw_square(center)

if __name__=='__main__':
    solve()
    sys.exit(0)