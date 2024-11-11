class Pillar:
    def __init__(self, index, next_index):
        self.disk_count = 1
        self.index = index
        self.prev_index = index - 1 if index > 0 else index
        self.next_index = next_index

    def __repr__(self):
        return f"<i:{self.index} - dc:{self.disk_count}>"

    def is_empty(self):
        return self.disk_count == 0


class Disk:
    def __init__(self, radius, pillar):
        self.radius = radius
        self.pillar = pillar

    def __repr__(self):
        return f"<r:{self.radius} - pi:{self.pillar.index}>"


def can_place(moving_disk, target_disk, empty_pillars_between):
    first_condition = empty_pillars_between or abs(moving_disk.pillar.index - target_disk.pillar.index) == 1
    second_condition = moving_disk.pillar.disk_count == 1
    third_condition = moving_disk.radius < target_disk.radius
    return first_condition and second_condition and third_condition


def move_disk(disk, on_disk):
    disk.pillar.disk_count = 0
    unsorted_pillars[disk.pillar.prev_index].next_index = disk.pillar.next_index
    unsorted_pillars[disk.pillar.next_index].prev_invex = disk.pillar.prev_index
    disk.pillar = on_disk.pillar


def are_pillars_between_empty(pillars, start_index, end_index):
    return pillars[start_index].next_index == end_index
    # for j in range(start_index + 1, end_index):
    #     if not pillars[j].is_empty():
    #         return False
    # return True


def parse_input():
    for j, value in enumerate(input().split(' ')):
        unsorted_pillars.append(Pillar(j, j + 1 if j + 1 < pillar_count else j))
        unsorted_disks.append(Disk(int(value), unsorted_pillars[j]))

    return sorted(unsorted_disks, key=lambda d: d.radius, reverse=True)


def can_solve():
    for i in range(0, len(sorted_disks) - 1):
        start_pillar_index = sorted_disks[i].pillar.index \
            if sorted_disks[i].pillar.index < sorted_disks[i + 1].pillar.index \
            else sorted_disks[i + 1].pillar.index

        end_pillar_index = sorted_disks[i].pillar.index \
            if sorted_disks[i].pillar.index > sorted_disks[i + 1].pillar.index \
            else sorted_disks[i + 1].pillar.index

        empty_pillars = are_pillars_between_empty(unsorted_pillars, start_pillar_index, end_pillar_index)

        if not can_place(sorted_disks[i + 1], sorted_disks[i], empty_pillars):
            return False
        else:
            move_disk(sorted_disks[i + 1], sorted_disks[i])

    return True


if __name__ == '__main__':
    pillar_count = int(input())

    unsorted_pillars = []
    unsorted_disks = []

    sorted_disks = parse_input()

    print('YES' if can_solve() else 'NO')
