#!/usr/bin/python3

from math import *
import sys

if len(sys.argv) < 2:
    exit(84)

def to_int(arg):
    try :
        return int(arg)
    except ValueError:
        exit(84)

if sys.argv[1] == '-h':
    print("USAGE\n\t./104intersection opt xp yp zp xv yv zv p\n")
    print("DESCRIPTION\n\topt         \tsurface option: 1 for a sphere, 2 for a cylinder, 3 for a cone")
    print("\t(xp, yp, zp)\tcoordinates of a point by which the light ray passes through")
    print("\t(xv, yv, zv)\tcoordinates of a vector parallel to the light ray")
    print("\tp           \tparameter: raduis of the sphere, radius of the cylinder, or")
    print("\t            \tangle formed by the cone and the Z-axis")

if len(sys.argv) != 9:
    exit(84)

if sys.argv[1] != '1' and sys.argv[1] != '2' and sys.argv[1] != '3':
    exit(84)

if sys.argv[1] == '1' and sys.argv[8] < '0':
    exit(84)

if sys.argv[1] == '2' and sys.argv[8] < '0':
    exit(84)

if sys.argv[1] == '3' and sys.argv[8] < '0':
    exit(84)


opt = to_int(sys.argv[1])

xp = to_int(sys.argv[2])
yp = to_int(sys.argv[3])
zp = to_int(sys.argv[4])

xv = to_int(sys.argv[5])
yv = to_int(sys.argv[6])
zv = to_int(sys.argv[7])

p = to_int(sys.argv[8])

if sys.argv[1] == '3' and sys.argv[8][0] == '-' :
    exit (84)

if sys.argv[1] == '3' and p >= 90 or p <= 0 :
    exit(84)

if opt == 1:
    print("Sphere of radius",p)
    print("Line passing through the point (%d, %d, %d) and parallel to the vector (%d, %d, %d)" %(xp, yp, zp, xv, yv, zv))
    a = xv**2 + yv**2 + zv**2
    b = (xp * xv + yp * yv + zp * zv)*2
    c = xp**2 + yp**2 + zp**2 - p**2
    delta = (b)**2 - (4 * a * c)
    if delta == 0:
        solution = (-b) / (2 * a)
        x1 = xv * solution + xp
        x2 = yv * solution + yp
        x3 = zv * solution + zp
        print("1 intersection point:")
        print("(%.3f, %.3f, %.3f)" %(x1, x2, x3))
    elif delta < 0 :
        print("No intersection point.")
    else :
        solution1 = ((-b) + sqrt(delta)) / (2 * a)
        solution2 = ((-b) - sqrt(delta)) / (2 * a)
        print("2 intersection points:")
        x1 = xv * solution1 + xp
        x2 = yv * solution1 + yp
        x3 = zv * solution1 + zp
        print("(%.3f, %.3f, %.3f)" %(x1, x2, x3))
        x1 = xv * solution2 + xp
        x2 = yv * solution2 + yp
        x3 = zv * solution2 + zp
        print("(%.3f, %.3f, %.3f)" %(x1, x2, x3))



if opt == 2:
    print("Cylinder of radius",p)
    print("Line passing through the point (%d, %d, %d) and parallel to the vector (%d, %d, %d)" %(xp, yp, zp, xv, yv, zv))
    a = xv**2 + yv**2
    b = (xp * xv)*2 + (yp * yv)*2
    c = xp**2 + yp**2 - p**2
    delta = (b)**2 - (4 * a * c)
    if xp**2 + yp**2 == p**2 and xv == 0 and yv == 0:
        print("There is an infinite number of intersection points.")
    elif delta == 0:
        solution = (-b) / (2 * a)
        x1 = xv * solution + xp
        x2 = yv * solution + yp
        x3 = zv * solution + zp
        print("1 intersection point:")
        print("(%.3f, %.3f, %.3f)" %(x1, x2, x3))
    elif delta < 0 :
        print("No intersection point.")
    else :
        solution1 = ((-b + sqrt(delta)) / (2 * a))
        solution2 = ((-b - sqrt(delta)) / (2 * a))
        print("2 intersection points:")
        x1 = xv * solution1 + xp
        x2 = yv * solution1 + yp
        x3 = zv * solution1 + zp
        print("(%.3f, %.3f, %.3f)" %(x1, x2, x3))
        x1 = xv * solution2 + xp
        x2 = yv * solution2 + yp
        x3 = zv * solution2 + zp
        print("(%.3f, %.3f, %.3f)" %(x1, x2, x3))



if opt == 3:
    print("Cone with a",p,"degree angle")
    print("Line passing through the point (%d, %d, %d) and parallel to the vector (%d, %d, %d)" %(xp, yp, zp, xv, yv, zv))
    p = p * pi / 180
    a = xv**2 + yv**2 - zv**2 * tan(p)**2
    b = (xp * xv * 2) + (yp * yv * 2) - (2 * zp * zv) * tan(p)**2
    c = xp**2 + yp**2  - zp**2 * tan(p)**2
    delta = (b)**2 - (4 * a * c)
    if xv == 0 and yv == 0:
        print("There is an infinite number of intersection points.")
    if delta == 0:
        solution = (-b) / (2 * a)
        x1 = xv * solution + xp
        x2 = yv * solution + yp
        x3 = zv * solution + zp
        print("1 intersection point:")
        print("(%.3f, %.3f, %.3f)" %(x1, x2, x3))
    elif delta < 0 :
        print("No intersection point.")
    else :
        solution1 = ((-b) + sqrt(delta)) / (2 * a)
        solution2 = ((-b) - sqrt(delta)) / (2 * a)
        print("2 intersection points:")
        x1 = xv * solution1 + xp
        x2 = yv * solution1 + yp
        x3 = zv * solution1 + zp
        print("(%.3f, %.3f, %.3f)" %(x1, x2, x3))
        x1 = xv * solution2 + xp
        x2 = yv * solution2 + yp
        x3 = zv * solution2 + zp
        print("(%.3f, %.3f, %.3f)" %(x1, x2, x3))

        

#EQUATION DU CYLINDRE = x² + y² = R²

#EQUATION D'UNE SPHERE = x² + y² + z² = R²

#EQUATION D'UN CONE = x² + y² - z²/tg²(angle) = 0

#CYLINDRE:

#ax² + bx + c:

#a = x2² + y2²
#b = (x1 * x2)*2 + (y1 * y2)*2
#c = x1² + y1² - p²

#SPHERE:

#a = x2² + y2² + z2²
#b = (x1 * x2)*2 + (y1 * y2)*2 + (z1 * z2)*2
#c = x1² + y1² + z1² - p²

