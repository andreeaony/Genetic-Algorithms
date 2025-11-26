# 📐 Computational Geometry & Genetic Algorithms

This repository contains multiple C++ implementations developed for the **Advanced Algorithms** course.  
The tasks include computational geometry algorithms and a genetic algorithm for function optimization.

Each program is documented and structured for clarity and performance.

---

## Contents Overview

### 1️⃣ Point Position Relative to the Circumcircle of Three Points 
*Find it in lab5AA folder*

This program reads three points that uniquely determine a circumcircle and a set of query points.  
Using the sign of a determinant (4×4 matrix), it classifies each point as:

- **Inside the circle**
- **On the circle**
- **Outside the circle**

---

### 2️⃣ Diagonal Legality in a Convex Quadrilateral 
*Find it in lab6AA folder*

Given four points forming a convex quadrilateral, the program verifies whether diagonals:

- **AC**
- **BD**

lie completely inside the polygon or not.  
Determinant evaluation determines whether each diagonal is:

- **LEGAL** → Properly inside the convex hull  
- **ILLEGAL** → Intersects exterior region  

---

### 3️⃣ Region Classification Using Half-Planes
*Find it in lab7AA folder*

The program processes constraints of the form:
ax + by + c ≤ 0

It evaluates whether the intersection of all half-planes forms a region that is:

- **VOID** → No feasible solution exists
- **BOUNDED** → Feasible region is finite
- **UNBOUNDED** → Solutions extend to infinity

---

### 4️⃣ Genetic Algorithm — Polynomial Maximization
Implements a GA designed to maximize a 4th-degree polynomial:
f(x) = Ax⁴ + Bx³ + Cx² + Dx + E

#### GA Components:
| Stage | Method |
|------|--------|
| Encoding | Binary chromosome |
| Fitness | Evaluation of f(x) |
| Selection | Roulette wheel + elitism |
| Crossover | Single-point, probabilistic |
| Mutation | Bit-flip mutation |
| Output | Best & average fitness per generation |

📄 Results exported to: `Evolutie.txt`

---

## 📈 Learning Outcomes

✔ Correct use of geometric predicates

✔ Determinant-based classification methods

✔ Region feasibility under linear constraints

✔ Implementation of a complete evolutionary algorithm
