import pytest
import fracpy
class TestClass:
    def test_lambda(self):
        assert(fracpy.rec_formula(1+1j, 2+3j) == 2 + 5j)

    def test_n_iter(self):
        assert(fracpy.n_iter(0+0j, 3+3j, 100, 4) < 100)
