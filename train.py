# -*- coding: utf-8 -*-
# Script de traitement de la première passe pour calculer le bitrate target de chaque GOP pour la passe 2

import sys
import math
import time
import random
import unittest
from threading import *

def is_anagram(s1, s2):
    if (len(s1) != len(s2)):
        return False
    val = 0;
    for c in s1:
        val += ord(c)
    for c in s2:
        val -= ord(c)
    return (val == 0)

verrou = RLock()

class Afficheur(Thread):
    """Thread chargé simplement d'afficher un mot dans la console."""

    def __init__(self, mot):
        Thread.__init__(self)
        self.mot = mot

    def run(self):
        """Code à exécuter pendant l'exécution du thread."""
        i = 0
        while i < 5:
            with verrou:
                for lettre in self.mot:
                    sys.stdout.write(lettre)
                    sys.stdout.flush()
                    attente = 0.2
                    attente += random.randint(1, 60) / 100
                    time.sleep(attente)

            i += 1


# Création des threads
thread_1 = Afficheur("canard")
thread_2 = Afficheur("TORTUE")

# Lancement des threads
# thread_1.start()
# thread_2.start()

# Attend que les threads se terminent
# thread_1.join()
# thread_2.join()

class RandomTest(unittest.TestCase):

    """Test case utilisé pour tester les fonctions du module 'random'."""

    def setUp(self):
        """Initialisation des tests."""
        self.liste = list(range(10))

    def test_choice(self):
        """Test le fonctionnement de la fonction 'random.choice'."""
        elt = random.choice(self.liste)
        self.assertIn(elt, self.liste)

    def test_shuffle(self):
        """Test le fonctionnement de la fonction 'random.shuffle'."""
        random.shuffle(self.liste)
        self.liste.sort()
        self.assertEqual(self.liste, list(range(10)))

    def test_sample(self):
        """Test le fonctionnement de la fonction 'random.sample'."""
        extrait = random.sample(self.liste, 5)
        for element in extrait:
            self.assertIn(element, self.liste)

        with self.assertRaises(ValueError):
            random.sample(self.liste, 20)

    def test_anagram(self):
        """Test la fonction is_anagram"""
        self.assertTrue(is_anagram("salut", "sautl"))
        self.assertTrue(is_anagram("", ""))
        self.assertTrue(is_anagram("gggggg0", "ggg0ggg"))
        self.assertFalse(is_anagram("salut", "sautll"))
        self.assertFalse(is_anagram("", "sautll"))
        self.assertFalse(is_anagram("45", "44"))

# unittest.main()

