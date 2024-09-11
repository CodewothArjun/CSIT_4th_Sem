import unittest
from typing import Set, Optional


class Position:
    def __init__(self, locname: Optional[str] = None):
        self.locname = locname

    def __str__(self) -> str:
        return self.locname if self.locname else "unknown"


class HasHeight:
    def __init__(self, height: int = 0):
        self.height = height


class HasPosition:
    def __init__(self, at: Optional[Position] = None):
        self.at = at


class Monkey(HasHeight, HasPosition):
    def __init__(self, height: int = 0, at: Optional[Position] = None):
        HasHeight.__init__(self, height)
        HasPosition.__init__(self, at)


class PalmTree(HasHeight, HasPosition):
    def __init__(self, height: int = 2, at: Optional[Position] = None):
        HasHeight.__init__(self, height)
        HasPosition.__init__(self, at)


class Box(HasHeight, HasPosition):
    def __init__(self, height: int = 2, at: Optional[Position] = None):
        HasHeight.__init__(self, height)
        HasPosition.__init__(self, at)


class Banana(HasHeight, HasPosition):
    def __init__(self, height: int, attached: PalmTree, owner: Optional[Monkey] = None):
        HasHeight.__init__(self, height)
        HasPosition.__init__(self, attached.at)  # Set initial position
        self.attached = attached
        self.owner = owner


class World:
    def __init__(self):
        self.locations: Set[Position] = set()


# Define your functions
def go(monkey: Monkey, where: Position) -> str:
    assert where in w.locations, "Position not in world locations"
    assert monkey.height == 0, "Monkey can only move while on the ground"
    monkey.at = where
    return f"Monkey moved to {where}"


def push(monkey: Monkey, box: Box, where: Position) -> str:
    assert monkey.at == box.at, "Monkey must be at the same position as the box"
    assert where in w.locations, "Position not in world locations"
    assert monkey.height == 0, "Monkey can only move the box while on the ground"
    monkey.at = where
    box.at = where
    return f"Monkey moved box to {where}"


def climb_up(monkey: Monkey, box: Box) -> str:
    assert monkey.at == box.at, "Monkey must be at the same position as the box"
    assert monkey.height == 0, "Monkey must be on the ground to climb"
    monkey.height += box.height
    return "Monkey climbs the box"


def grasp(monkey: Monkey, banana: Banana) -> str:
    assert monkey.height == banana.height, "Monkey's height must match banana's height"
    assert monkey.at == banana.at, "Monkey must be at the same position as the banana"
    banana.owner = monkey
    return "Monkey takes the banana"


def infer_owner_at(palmtree: PalmTree, banana: Banana) -> str:
    assert banana.attached == palmtree, "Banana must be attached to the palm tree"
    banana.at = palmtree.at
    return (
        "Remembered that if banana is on palm tree, its location is where palm tree is"
    )


def infer_banana_height(palmtree: PalmTree, banana: Banana) -> str:
    assert banana.attached == palmtree, "Banana must be attached to the palm tree"
    banana.height = palmtree.height
    return "Remembered that if banana is on the tree, its height equals tree's height"


class TestMonkeyActions(unittest.TestCase):
    def setUp(self):
        global w, p1, p2, p3, m, box, p, b
        p1 = Position("Position A")
        p2 = Position("Position B")
        p3 = Position("Position C")

        w = World()
        w.locations.update([p1, p2, p3])

        m = Monkey(at=p1)
        box = Box(at=p2)
        p = PalmTree(at=p3)
        b = Banana(height=p.height, attached=p)

    def test_go(self):
        result = go(m, p2)
        self.assertEqual(result, "Monkey moved to Position B")
        self.assertEqual(m.at, p2)

    def test_push(self):

        go(m, p2)
        result = push(m, box, p3)
        self.assertEqual(result, "Monkey moved box to Position C")
        self.assertEqual(m.at, p3)
        self.assertEqual(box.at, p3)

    def test_climb_up(self):
        m.height = 0
        go(m, p2)
        result = climb_up(m, box)
        self.assertEqual(result, "Monkey climbs the box")
        self.assertEqual(m.height, box.height)

    def test_grasp(self):
        m.height = p.height
        go(m, p3)
        result = grasp(m, b)
        self.assertEqual(result, "Monkey takes the banana")
        self.assertEqual(b.owner, m)

    def test_infer_owner_at(self):
        result = infer_owner_at(p, b)
        self.assertEqual(
            result,
            "Remembered that if banana is on palm tree, its location is where palm tree is",
        )
        self.assertEqual(b.at, p.at)

    def test_infer_banana_height(self):
        result = infer_banana_height(p, b)
        self.assertEqual(
            result,
            "Remembered that if banana is on the tree, its height equals tree's height",
        )
        self.assertEqual(b.height, p.height)


if __name__ == "__main__":
    unittest.main()