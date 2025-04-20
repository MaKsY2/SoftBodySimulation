### Soft body simulation project 

SFML-3.0.0 Mac/Arm_64 Already in project


## Definition of done:

- Softbody element
- Springs
- Mass points
- Custom env for mass points


# Some sci-stuff 

## Mass point model

Parametrs:
- x = Position vector
- v - Velocity vector
- F - Force vector
- m - mass
- delta_t - time between two frames

At the start of each frame: 
- F = 0
- F += all forces applied to an object
- v += (F * delta_t) / m
- x += v * delta_t


TBD...

Obsessed with projects again, no more useless people
