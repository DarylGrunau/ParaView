/*=========================================================================

  Program:   ParaView
  Module:    vtkSMExtractTriggerProxy.h

  Copyright (c) Kitware, Inc.
  All rights reserved.
  See Copyright.txt or http://www.paraview.org/HTML/Copyright.html for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notice for more information.

=========================================================================*/
/**
 * @class vtkSMExtractTriggerProxy
 * @brief trigger to control extract generation
 *
 * vtkSMExtractTriggerProxy defines a trigger that is intended to use a control
 * an extract generator. Currently, this class directly implements a time-based
 * trigger which relies on properties to indicate the start-time, end-time, and
 * update frequency. Subclasses can be added to define new types of triggers.
 */

#ifndef vtkSMExtractTriggerProxy_h
#define vtkSMExtractTriggerProxy_h

#include "vtkSMProxy.h"

class vtkSMExtractsController;

class VTKREMOTINGSERVERMANAGER_EXPORT vtkSMExtractTriggerProxy : public vtkSMProxy
{
public:
  static vtkSMExtractTriggerProxy* New();
  vtkTypeMacro(vtkSMExtractTriggerProxy, vtkSMProxy);
  void PrintSelf(ostream& os, vtkIndent indent) override;

  /**
   * Returns true if the trigger conditions are satisfied.
   */
  virtual bool IsActivated(vtkSMExtractsController* extractor);

protected:
  vtkSMExtractTriggerProxy();
  ~vtkSMExtractTriggerProxy();

private:
  vtkSMExtractTriggerProxy(const vtkSMExtractTriggerProxy&) = delete;
  void operator=(const vtkSMExtractTriggerProxy&) = delete;
};

#endif
