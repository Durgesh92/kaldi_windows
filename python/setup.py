import os
import re
import setuptools
from cmake_extensions import *

with open("README.md", "r") as fh:
    long_description = fh.read()

version = os.getenv("VERSION", "unknown")
if not re.match(r'^\d', version):
    version = '0.' + version

setuptools.setup(
    name="durgesh_ai",
    version=version,
    author="Durgesh Waghmare",
    author_email="waghmaredurgesh@gmail.com",
    description="API for Kald",
    long_description=long_description,
    long_description_content_type="text/markdown",
    url="",
    packages=setuptools.find_packages(),
    ext_modules=[CMakeExtension(name='_durgesh_ai', pkg_name='durgesh_ai')],
    cmdclass={'build_ext': CMakeBuildExt, 'build_py' : CMakeBuildExtFirst},
    classifiers=[
        'Programming Language :: Python :: 3',
        'License :: OSI Approved :: Apache Software License',
        'Operating System :: Microsoft :: Windows',
        'Operating System :: POSIX :: Linux',
        'Operating System :: MacOS :: MacOS X',
        'Topic :: Software Development :: Libraries :: Python Modules'
    ],
    python_requires='>=3.5',
)
