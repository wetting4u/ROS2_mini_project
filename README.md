# ROS2 Mini Project

## Project Overview
This project is a simple demonstration of ROS 2 (Robot Operating System 2) functionalities including node creation, topic communication, and service calls. It is designed as a learning tool and starter template for ROS 2 development.

---

## Table of Contents
- [Installation](#installation)
- [Environment Setup](#environment-setup)
- [Usage](#usage)
- [Project Structure](#project-structure)

---

## Installation

1. Ensure ROS 2 is installed (Humble or later recommended)  
   Official installation guide: [ROS 2 Installation](https://docs.ros.org/en/humble/Installation.html)

2. Clone this repository

```bash
git clone git@github.com:wetting4u/ROS2_mini_project.git
cd ROS2_mini_project

3. Build the workspace

```bash
colcon build

4. Source the workspace setup file

```bash
source install/setup.bash

## Environment setup

Recommended OS: Ubuntu 20.04 or 22.04
ROS 2 Humble or later
Python 3.x
colcon build tool


## Usage

Run Nodes
```bash
ros2 run <package_name> <executable_name>

Example:

```bash
ros2 run package_a node_a
ros2 run package_b node_b

## Project Structure
ROS2_mini_project/
├── package_a/
│   ├── src/
│   ├── include/
│   ├── package.xml
│   └── CMakeLists.txt
├── package_b/
│   ├── src/
│   ├── include/
│   ├── package.xml
│   └── CMakeLists.txt
├── src/
├── .gitignore
└── README.md
