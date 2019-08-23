PLEASE REFER TO THE APPLICATION NOTE FOR THIS MIDDLEWARE FOR MORE INFORMATION

r_riic_rx
=========

Overview
--------
The RIIC fit module provides a method to transmit and receive data between 
the master and slave devices using the I2C-bus interface (RIIC). 
The RIIC is in compliance with single master mode of the XP I2C-bus (Inter-IC-Bus) interface.

The driver supports one channels available on the mcu.
The driver can be reducedin size by removing code used for parameter checking orfor unused channels.
These configuration options can be found in "r_config\r_riic_rx_config.h".
An original copy of the configuration file is stored in "r_riic_rx\ref\r_riic_rx_config_reference.h".

Features
--------
* Master transmission, master reception, slave transmission, and slave reception.
* Multi-master configuration which is that communication is arbitrated between multiple masters and a single slave.
* Communication mode can be normal or fast mode and the maximum communication rate is 400 kbps at a maximum. 
  However channel 0 of RX64M and RX65N, RX71M supports fast mode plus and the maximum communication rate is 1 Mbps.

File Structure
--------------
r_riic_rx
|   readme.txt
|   r_riic_rx_if.h
|
+---doc
|   |
|   +---en
|   |   r01an1692ej{VERSION_NUMBER}-rx-riic.pdf
|   |
|   +---ja
|       r01an1692jj{VERSION_NUMBER}-rx-riic.pdf
|
+---ref
|       r_riic_rx_config_reference.h
|       r_riic_rx_pin_config_reference.h
|
+---src
    |   r_riic_rx.c
    |   r_riic_rx_private.h
    |
    +---targets
        |
        +---rx110
        |      r_riic_rx110.c
        |      r_riic_rx110_private.h
        |
        +---rx111
        |      r_riic_rx111.c
        |      r_riic_rx111_private.h
        |
        +---rx113
        |      r_riic_rx113.c
        |      r_riic_rx113_private.h
        |
        +---rx130
        |      r_riic_rx130.c
        |      r_riic_rx130_private.h
        |
        +---rx230
        |      r_riic_rx230.c
        |      r_riic_rx230_private.h
        |
        +---rx231
        |      r_riic_rx231.c
        |      r_riic_rx231_private.h
        |
        +---rx23t
        |      r_riic_rx23t.c
        |      r_riic_rx23t_private.h
        |
        +---rx24t
        |      r_riic_rx24t.c
        |      r_riic_rx24t_private.h
        |
        +---rx24u
        |      r_riic_rx24u.c
        |      r_riic_rx24u_private.h
        |
        +---rx64m
        |      r_riic_rx64m.c
        |      r_riic_rx64m_private.h
        |
        +---rx65n
        |      r_riic_rx65n.c
        |      r_riic_rx65n_private.h
        |
        +---rx66t
        |      r_riic_rx66t.c
        |      r_riic_rx66t_private.h
        |
        +---rx71m
        |       r_riic_rx71m.c
        |       r_riic_rx71m_private.h
        |
        +---rx72t
                r_riic_rx72t.c
                r_riic_rx72t_private.h

r_config
    r_riic_rx_config.h
    r_riic_rx_pin_config.h
