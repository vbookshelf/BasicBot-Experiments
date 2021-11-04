
# Ref tutorial:
# ExplainingComputers
# Episode 4: https://www.explainingcomputers.com/pi_devastator_videos.html

# Pygame is used to create games.
# Here we are using it to detect when a user presses or
# releases a key.

import pygame

# We must open a Pygame window to allow it to detect user events.
# In Pygame, user interactions are called events.
# Pygame can only detect an event if a Pygame window is
# open and it has the focus (i.e. it is selected).
# We can specify any window size. Here we have specified 240x160 (height, width).
screen = pygame.display.set_mode([240, 160])

while True:
    
    # loop through a list containing the events
    for event in pygame.event.get():
        
        # if the user presses a key down
        if event.type == pygame.KEYDOWN:
            
            if event.key == pygame.K_RIGHT:
                print('Right')
            if event.key == pygame.K_LEFT:
                print('Left')
            if event.key == pygame.K_UP:
                print('Up')
            if event.key == pygame.K_DOWN:
                print('Down')
			
			# Close Pygame if the user presss q
            if event.key == pygame.K_q:
                pygame.quit()
        
        # if the user releases a key (after pressing it)
        elif event.type == pygame.KEYUP:
            print('Key-up detected')
			
			
	