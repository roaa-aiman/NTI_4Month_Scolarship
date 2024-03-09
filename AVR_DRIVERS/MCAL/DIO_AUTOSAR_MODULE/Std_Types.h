/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *    File:  Std_Types.h
 *    SW Version: 1.0.0
 *    Autosar Version : 4.4.0
 *    Description:  AUTOSAR Base _ Standard Types Definition
 *    Author : Roaa Aiman 
 *********************************************************************************************************************/

#ifndef STD_TYPES_H
#define STD_TYPES_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/

# include "Platform_Types.h"
# include "Compiler.h"


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/* Id for the company in the AUTOSAR
 * for example Mohamed Tarek's ID = 1000 :) */
#define STD_TYPES_VENDOR_ID                           (123)

/*
 * Module Version 1.0.0
 */
#define STD_SW_MAJOR_VERSION                           (1U)
#define STD_SW_MINOR_VERSION                           (0U)
#define STD_SW_PATCH_VERSION                           (0U)

/*
 * AUTOSAR Version 4.4.0
 */
#define STD_TYPES_AR_RELEASE_MAJOR_VERSION             (4U)
#define STD_TYPES_AR_RELEASE_MINOR_VERSION             (4U)
#define STD_TYPES_AR_RELEASE_PATCH_VERSION             (0U)

#define STD_HIGH        0x01U       /* Standard HIGH */
#define STD_LOW         0x00U       /* Standard LOW */

#define LOGIC_HIGH        0x01U       /* Standard HIGH */
#define LOGIC_LOW         0x00U       /* Standard LOW */

#define STD_ACTIVE      0x01U       /* Logical state active */
#define STD_IDLE        0x00U       /* Logical state idle */

#define STD_ON          0x01U       /* Standard ON */
#define STD_OFF         0x00U       /* Standard OFF */

/*This type can be used as standard API return type which is shared between the RTE
and the BSW modules. It shall be defined as follows:
*/
typedef uint8            Std_ReturnType;
#define E_OK            ((Std_ReturnType)0x00U)      /* Function Return OK */
#define E_NOT_OK        ((Std_ReturnType)0x01U)      /* Function Return NOT OK */

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/*
 *  Describes the standard Return Type Definitions used in the project
 */


/*
 * Structure for the Version of the module.
 * This is requested by calling <Module name>_GetVersionInfo()
 */
typedef struct
{
  uint16  vendorID;
  uint16  moduleID;
  uint8 sw_major_version;
  uint8 sw_minor_version;
  uint8 sw_patch_version;
} Std_VersionInfoType;



/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/


#endif /* STD_TYPES_H */
/**********************************************************************************************************************
 *  END OF FILE: Std_Types.h
 *********************************************************************************************************************/